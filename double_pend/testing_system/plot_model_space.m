
x = squeeze(good_out22_2.x(1,:,:)) % reshape magic
xd = squeeze(good_out22_2.xd(1,:,:)) % reshape magic

x2 = squeeze(good_out22.x(1,:,:)) % reshape magic
xd2 = squeeze(good_out22.xd(1,:,:)) % reshape magic


x3 = squeeze(untuned.x(1,:,:)) % reshape magic
xd3 = squeeze(untuned.xd(1,:,:)) % reshape magic

hold on
plot(x,xd)

plot(x2,xd2)
plot(x3,xd3)