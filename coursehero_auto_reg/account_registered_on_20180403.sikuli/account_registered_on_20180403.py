from random import randint
if exists("1522804305282.png"):
    while 2>1 :
        wait(1)
        click("1522804403753.png")
        x = randint(0,3)
        if x==0:
            click(Pattern("1522806457711.png").targetOffset(100,142))
            
            click(Pattern("1522804705670.png").targetOffset(-4,74))
        if x==1:
            click(Pattern("1522806457711.png").targetOffset(101,189))
            click(Pattern("1522806457711.png").targetOffset(101,189))
            click(Pattern("1522805625975.png").targetOffset(4,136))
        if x==2:
            click(Pattern("1522806457711.png").targetOffset(106,133))
            click(Pattern("1522806457711.png").targetOffset(104,193))
            click(Pattern("1522806457711.png").targetOffset(104,193))
            click(Pattern("1522806205013.png").targetOffset(1,164))
        if x==3:
            click(Pattern("1522806457711.png").targetOffset(104,193))
            click(Pattern("1522806457711.png").targetOffset(104,193))
            click(Pattern("1522806457711.png").targetOffset(104,193))
            click(Pattern("1522806457711.png").targetOffset(104,193))
            click(Pattern("1522806311623.png").targetOffset(1,211))
            
        print(x) 
    