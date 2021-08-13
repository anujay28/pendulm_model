
linewidth = 2;

x1_22 = squeeze(test_22_output.x(1,:,:)) % reshape magic
xd1_22 = squeeze(test_22_output.xd(1,:,:)) % reshape magic

x1_23 = squeeze(test_23_output.x(1,:,:)) % reshape magic
xd1_23 = squeeze(test_23_output.xd(1,:,:)) % reshape magic

x1_24 = squeeze(test_24_output.x(1,:,:)) % reshape magic
xd1_24 = squeeze(test_24_output.xd(1,:,:)) % reshape magic

x1_25 = squeeze(test_25_output.x(1,:,:)) % reshape magic
xd1_25 = squeeze(test_25_output.xd(1,:,:)) % reshape magic

x1_un = squeeze(test_untunned_output.x(1,:,:)) % reshape magic
xd1_un = squeeze(test_untunned_output.xd(1,:,:)) % reshape magic



x2_22 = squeeze(test_22_output.x(2,:,:)) % reshape magic
xd2_22 = squeeze(test_22_output.xd(2,:,:)) % reshape magic

x2_23 = squeeze(test_23_output.x(2,:,:)) % reshape magic
xd2_23 = squeeze(test_23_output.xd(2,:,:)) % reshape magic

x2_24 = squeeze(test_24_output.x(2,:,:)) % reshape magic
xd2_24 = squeeze(test_24_output.xd(2,:,:)) % reshape magic

x2_25 = squeeze(test_25_output.x(2,:,:)) % reshape magic
xd2_25 = squeeze(test_25_output.xd(2,:,:)) % reshape magic

x2_un = squeeze(test_untunned_output.x(2,:,:)) % reshape magic
xd2_un = squeeze(test_untunned_output.xd(2,:,:)) % reshape magic



subplot(2,1,1);
hold on

plot(x1_un, xd1_un,'LineWidth',linewidth);
plot(x1_22, xd1_22,'LineWidth',linewidth);
%plot(x1_23, xd1_23,'LineWidth',2);
plot(x1_24, xd1_24,'LineWidth',linewidth);
plot(x1_25, xd1_25,'LineWidth',linewidth);
title('Joint 1')
xlabel('$X$','interpreter','latex','FontSize',20)
ylabel('$\dot{X}$','interpreter','latex', 'rotation',0, 'FontSize',20)
legend('untunned', 'pos+vel cost','pos cost', 'vel cost')


subplot(2,1,2);
hold on
plot(x2_un, xd2_un,'LineWidth',linewidth);
plot(x2_22, xd2_22,'LineWidth',linewidth);
%plot(x1_23, xd1_23,'LineWidth',2);
plot(x2_24, xd2_24,'LineWidth',linewidth);
plot(x2_25, xd2_25,'LineWidth',linewidth);
title('Joint 2')
xlabel('$X$','interpreter','latex','FontSize',20)
ylabel('$\dot{X}$','interpreter','latex', 'rotation',0, 'FontSize',20)