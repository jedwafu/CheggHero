wait(Pattern("1521870900837.png").similar(0.64).targetOffset(7,19))
wait(1)
click(Pattern("1521870900837.png").similar(0.64).targetOffset(7,19))
wait(3)
if exists (Pattern("1521870961070.png").targetOffset(0,58)):
    click(Pattern("1521870961070.png").targetOffset(0,58))
else:
    print("openVPN error")
