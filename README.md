江大校科协软件技术中心
------
这个仓库用来提交代码，相互学习，

---------------

## 安装提纲

1. [下载安装git](https://git-scm.com/downloads)

2. [申请github账号](https://github.com/)

3. 设置git

	1. 使用Git Bash生成新的ssh key。
		$ cd ~  #保证当前路径在”~”下
		$ ssh-keygen -t rsa -C "xxxxxx@yy.com"  #建议填写自己真实有效的邮箱地址
		Generating public/private rsa key pair.
		Enter file in which to save the key (/c/Users/xxxx_000/.ssh/id_rsa):   #不填直接回车
		Enter passphrase (empty for no passphrase):   #输入密码（可以为空）
		Enter same passphrase again:   #再次确认密码（可以为空）
		Your public key has been saved in /c/Users/xxxx_000/.ssh/id_rsa.pub.  #生成的公钥
		The key fingerprint is:
		e3:51:33:xx:xx:xx:xx:xxx:61:28:83:e2:81 xxxxxx@yy.com
		*本机已完成ssh key设置，其存放路径为：c:/Users/xxxx_000/.ssh/下。
		注释：可生成ssh key自定义名称的密钥，默认id_rsa。

		$ ssh-keygen -t rsa -C "邮箱地址" -f ~/.ssh/githug_blog_keys #生成ssh key的名称为githug_blog_keys，慎用容易出现其它异常。
	2. 添加ssh key到GItHub
        登录GitHub系统；点击右上角账号头像的“▼”→Settings→SSH kyes→Add SSH key。
	3. 复制id_rsa.pub的公钥内容。 
		1) 进入c:/Users/xxxx_000/.ssh/目录下，打开id_rsa.pub文件，全选复制公钥内容。
		2) Title自定义，将公钥粘贴到GitHub中Add an SSH key的key输入框，最后“Add Key”。
	4.配置账户
		$ git config --global user.name “your_username”  #设置用户名
		$ git config --global user.email “your_registered_github_Email”  #设置邮箱地址(建议用注册giuhub的邮箱)
5. 测试ssh keys是否设置成功。
	$ ssh -T git@github.com
	The authenticity of host 'github.com (192.30.252.129)' can't be established.
	RSA key fingerprint is 16:27:xx:xx:xx:xx:xx:4d:eb:df:a6:48.
	Are you sure you want to continue connecting (yes/no)? yes #确认你是否继续联系，输入yes
	Warning: Permanently added 'github.com,192.30.252.129' (RSA) to the list of known hosts

6. [加入我们](https://github.com/JNUTRDC/TRDC/invitations)

7. 提交代码
在本地创建项目文件，在 Bash 下键入一下代码： <br>
mkdir test  //创建目录<br>
cd test     //链接到此目录<br>
git init    //创建本地产库产库<br>
git add README<br>
git commit -m 'first commit'<br>
git remote add origin git@github.com:JNUTRDC/TRDC.git<br>
git push -u origin master



-------
有疑问欢迎提问
