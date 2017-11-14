using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace xixiaxixi.RememberGame
{
#region
    class Program
    {
        static void Main(string[] args)
        {
            bool canContinue = true;
            Game g = new Game
                (
                (s, a) => Print(s),
                (s, a) => { if (a.isSame == false) System.Threading.Thread.Sleep(2000); },
                (s, a) => { Console.WriteLine("\nyou win"); canContinue = false; },
                (s, a) => Print(a.parent)
                );

            while (canContinue)
            {
                string xy = Console.ReadLine();
                string[] xandy = xy.Split(' ');
                try
                {
                    g.Input(Convert.ToInt32(xandy[0]), Convert.ToInt32(xandy[1]));
                }
                catch(Exception e)
                {
                    if(e.Message!= "card has cleared!!!" && e.Message!= "card has enactived!!!")
                    {
                        throw e;
                    }
                    else
                    {
                        Console.WriteLine("input error");
                    }
                }
            }
        }

        public static void Print(Game g)
        {
            for (int i = 0; i < Game.rowCount; i++)
            {
                for (int j = 0; j < Game.columnCount; j++)
                {
                    Console.Write(g[4 * i + j]);
                }
                Console.WriteLine();
            }
        }
        
    }
#endregion
#region
    /**
     *  下面是Card的定义
     */
    public enum changeEnum
    {
        active,
        clear
    }

    public class ChangeArgs
    {
        public readonly changeEnum change;
        public readonly bool toState;
        public readonly Game parent;
        public ChangeArgs(changeEnum change, bool toState, Game parent)
        {
            this.change = change;
            this.toState = toState;
            this.parent = parent;
        }
    }

    public delegate void OnCardStateChanged(Card sender, ChangeArgs args);

    public class Card
    {
        private OnCardStateChanged onCardStateChanged;

        private Game parent;

        private int _id;
        public int Id
        {
            get
            {
                return _id;
            }
            set
            {
                _id = value;
            }
        }

        private bool _isActive;
        public bool IsActive
        {
            get
            {
                return _isActive;
            }
            set
            {
                if (value != _isActive)
                {
                    _isActive = value;
                    onCardStateChanged?.Invoke(this, new ChangeArgs(changeEnum.active, value, parent));
                }
            }
        }

        private bool _isClear;
        public bool IsClear
        {
            get
            {
                return _isClear;
            }
            set
            {

                if (value != _isClear)
                {
                    _isClear = value;
                    onCardStateChanged?.Invoke(this, new ChangeArgs(changeEnum.clear, value, parent));
                }
            }
        }

        public override string ToString()
        {
            if (_isClear)
            {
                return "  ";
            }else if (_isActive)
            {
                return _id.ToString() + " ";
            }
            else
            {
                return "* ";
            }
        }

        public Card(int id, Game parent, OnCardStateChanged onCardStateChanged)
        {
            this._id = id;
            this._isActive = false;
            this._isClear = false;
            this.parent = parent;
            this.onCardStateChanged = onCardStateChanged;
        }
    }
    //card定义结束
    #endregion
#region
    public delegate void OnGameStart(Game sender, GameArgs args);
    public delegate void OnGameOver(Game sender, GameArgs args);
    public delegate void OnGamePause(Game sender, GameArgs args);

    public class GameArgs
    {
        public bool isSame;
    }

    public class Game
    {
        public const int rowCount = 4;
        public const int columnCount = 4;

        public OnGameStart onGameStart;
        public OnGamePause onGamePause;
        public OnGameOver onGameOver;

        private List<Card> card;

        private Card _firstCard;
        private Card _secondCard;
        private int _clearPairCount;

        private void ShuffleCard()
        {
            Random random = new Random();
            for (int i = 0; i < card.Count; i++)
            {
                int r = random.Next(card.Count);
                Card temp = this.card[i];
                this.card[i] = this.card[r];
                this.card[r] = temp;
            }
        }

        private void initGame(OnCardStateChanged change)
        {
            this.card = new List<Card>(16);
            for (int i = 0; i < rowCount*columnCount; i++)
            {
                this.card.Add(new Card(i / 2, this, change));
            }
            ShuffleCard();
            _firstCard = null;
            _secondCard = null;
            _clearPairCount = 0;

        }

        public Game(OnGameStart start, OnGamePause pause, OnGameOver over, OnCardStateChanged change)
        {
            onGameStart = start;
            onGamePause = pause;
            onGameOver = over;
            initGame(change);
            onGameStart?.Invoke(this, new GameArgs());
        }

        public void Input(int x,int y)
        {
            if (_firstCard == null)
            {
                Card chosencard = this.card[columnCount * y + x];
                if (chosencard.IsClear)
                {
                    throw new Exception("card has cleared!!!");
                }
                else if (chosencard.IsActive)
                {
                    throw new Exception("card has enactived!!!");
                }
                else
                {
                    _firstCard = chosencard;
                    chosencard.IsActive = true;
                }
            } else if (_secondCard == null)
            {
                Card chosencard = this.card[columnCount * y + x];
                if (chosencard.IsClear)
                {
                    throw new Exception("card has cleared!!!");
                }
                else if (chosencard.IsActive)
                {
                    throw new Exception("card has enactived!!!");
                }
                else
                {
                    _secondCard = chosencard;
                    chosencard.IsActive = true;
                }
            }

            if (_firstCard != null && _secondCard != null)
            {
                if (_firstCard.Id == _secondCard.Id)
                {
                    _firstCard.IsClear = true;
                    _secondCard.IsClear = true;
                    _clearPairCount++;
                }
                else
                {
                    onGamePause?.Invoke(this, new GameArgs { isSame = true });
                    _firstCard.IsActive = false;
                    _secondCard.IsActive = false;
                }

                _firstCard = null;
                _secondCard = null;
            }

            if (_clearPairCount == rowCount * columnCount / 2)
            {
                onGameOver?.Invoke(this, new GameArgs());
            }
        }

        public Card this[int index]{
            get
            {
                return this.card[index];
            }
        }

    }
    #endregion
}
