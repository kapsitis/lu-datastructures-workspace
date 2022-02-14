Noisy Bears
==============

See [Olimps.lio.lv](http://olimps.lio.lv/uzdevumi.php?show=55)

**Time Limit:** 1 second

**Description:** 

Every issue of the newspaper *Postimees* there is a comic strip named "Noisy Bears". 
Unfortunately, sometimes the editors can link the same picture file 
on multiple days. As a supporter of "Noisy Bears" you want to know, how many 
of these comic strips have been published during the last year. 
You have stored the Web-links for these comic strips throughout the year. 
All the links look like this: 

```
http://www.postimees.ee/koomiks/karudXXXX.jpg,
```

where `XXXX` is the date when this image was created (publishing date(s) may 
differ from this). As it is known that their author Urmas Nemvalts
never makes two pictures on a single day, write a program to 
compute the number of different dates among these `XXXX`. 

**Input**

Text-file `bears.in` -- it specifies the total number of comic-strip links $N$
(N <=366), but every subsequent line contains a link to a comic strip (it is a 
single JPEG file). 

**Output**

Text-file `bears.out` -- the count of unique comic strips. 

**Example**

`bears.in`

```
5
http://www.postimees.ee/koomiks/karud0101.jpg
http://www.postimees.ee/koomiks/karud0103.jpg
http://www.postimees.ee/koomiks/karud0104.jpg
http://www.postimees.ee/koomiks/karud0103.jpg
http://www.postimees.ee/koomiks/karud0106.jpg
```

`bears.out`

```
4
```

