CnBlogsClient
=============

This is a client program for [http://www.cnblogs.com](http://www.cnblogs.com "博客园") which implemented using Qt framework. The purpose of this program is to provide a quick way to access to cnblogs for users. Besides, Qt is my favourite tool and I am enjoying when implementing this project.

----------

1. Introduction
============

##1.1 Features##
* **Login** to server use your blog account
* The `home page` of **www.cnblogs.com**
* The **picking** posts
* The **candidates posts** right now
* The posts you voted
* The posts you commented
* View the posts in your blog
* To **NOTIFY** you when new posts are created
* Flexible window layout

##1.2 HttpClient
To login to the web server of **www.cnblogs.com**, we have to assemble a http request first. **Libcurl** is a good helper to do something like this. This is a library written by pure C and it supports lots of protocols. Most importantly, libcurl can handle **cookies** file without programmers' intervention.     


##1.3 Htmlcxx
A question has to be asked when we try to login to web server without browsers like Chrome or IE:**How does the server know who am I?**. Though unkown to us, the server must have some methods to identify different clients. As for www.cnblogs.com, four parameters must appreared in the request URL. They are listed as follows:
 
- ```__EVENTTARGET ```, currently is **empty**
- ```__EVENTARGUMENT ```, currently is **empty**
- ```__VIEWSTATE ```, **different** according different users.
- ```__EVENTVALIDATION``` , **different** according different users.
- ```tbUserName=***```, user name
- ```tbPassword```, user password
- ```btnLogin```=%E7%99%BB++%E5%BD%95(unicode of `登录`)
- ```txtReturnUrl```=http%3A%2F%2Fwww.cnblogs.com%2F(**http://www.cnblogs.com/**)

2. Compilation
==============

2.1 Get the Source Code
-----------------------
Open your git bash and change to the directory into which you want to save the source code, and type the following command:

    $ git clone git@github.com:csuft/CnBlogsClient.git .
When the command finished, you can find a newly created directory in the path you choosed.
2.2 prerequisite
----------------
This project is build using Qt framework and two 3rd party libraries. If you want to recompile the source code, then you have to meet the following requirements:  

1. **Qt library** with version **5.2** or higher. Old versions may still work.  
2. ```libcurl-7.18.0-win32-msvc``` is the best choice. Since under my machine this is the only version which I compiled successfully.
3. ```htmlcxx-0.84``` is the latest version you can get on the website. You have to **COMPILE** the library first if you want to integrate it into your project. **NOTE:** you have to adjust the runtime library version to apply your project.


3. Screenshots
==============
![MethodOne.jpg](https://github.com/csuft/CnBlogsClient/raw/master/Screenshots/2014-07-24_204458.png "")

![MethodOne.jpg](https://github.com/csuft/CnBlogsClient/raw/master/Screenshots/Schirmfoto_2014-07-14_111003.png "")

![MethodOne.jpg](https://github.com/csuft/CnBlogsClient/raw/master/Screenshots/Schirmfoto_2014-07-14_111045.png "")

![MethodOne.jpg](https://github.com/csuft/CnBlogsClient/raw/master/Screenshots/Schirmfoto_2014-07-24_084258.png "")

4. License
==========
This software is licensed under LGPL, you can use or redistribute it freely.


