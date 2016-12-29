----------------------------
<h1 align="center">ORANGE'S The Implementation of Opreation System</h1>
<a name="Menu"></a>
##Menu
[Menu](#Menu)</br>
[Description](#Description)</br>
[Tools](#Tools)</br>
[Oters](#Oters)

<a name="Description"></a>
##[Description](#Menu)
<p align="justify">&nbsp;&nbsp;&nbsp;&nbsp;This responbility is consisted of some thought, notices and some codes when i read about < Oranges >. all the codes are checked one by one and try to make sure that ecah codes is running correctlly in <em> Linux Plantform</em> :).</br>&nbsp;&nbsp;&nbsp;&nbsp;There are 11 folders in it.</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap1</strong> is about a simple and basic boots code. using .asm.</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap3</strong> is about protect modle on X86 plantform. using .asm</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap4</strong> is about advanced protect modle on X86 plantform. using .asm</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap5</strong> is about a oroginal kernel, using .asm and .c, in this part the author using C to code and init IDT/GDT... finally, open the 83599 interrupter and capture signal of keyboard</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap6</strong> is about process in a kernel</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap7</strong> is about I/O system in a kernel</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap8</strong> is about IPC ( internal process communication ) in a kernel</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap9</strong> is about FS ( file system ) in a kernel</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap10</strong> is about memory management system in a kernel</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>chap11</strong> is about final of this system</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>commk</strong> is about a common makefile in a kernel</br>
</p>


<a name="Tools"></a>
##[Tools](#Menu)
<p align="justify">&nbsp;&nbsp;&nbsp;&nbsp;To run those codes, you need install some tools:</br>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>bochs</strong> -- is an simulator of X86 plantform. the lasted version is 2.4.6, you can install it by ` sudo apt-get install bochs bochs-x bximage vgabios` or by sources ( you can use this method to install a version without debug, to install a debug version, you should install it by source, it's reall complicated, <a href="http://blog.csdn.net/u011889952/article/details/52850001">reference here</a> )</br>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>qemu</strong> -- is another simulator of X86 plantform. you just need to choose one of them to simulate your kernel.</br>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>xxd</strong> -- is a tool for analysising memory and file system used in our proj.</br>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>readelf</strong> -- is a tool for analysising memory and file system used in our proj.</br>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>objdump</strong> -- is a tool for analysising memory and file system used in our proj.</br>
</p>

<a name="Oters"></a>
##[Oters](#Menu)
<p align="justify">&nbsp;&nbsp;&nbsp;&nbsp;It's great honours to me if it can make any benefit for you. Any problems in using it, please contract <a href="mailto:newplan001@163.com"><strong>ME</strong></a>.</p>

<p align="right">NEWPLAN</br>2016/10/15</p>
