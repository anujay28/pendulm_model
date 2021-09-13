
linewidth = 2;

x1_all = squeeze(all_cost_state_space.x(1,:,:)) % reshape magic
xd1_all = squeeze(all_cost_state_space.xd(1,:,:)) % reshape magic


x1_pos = squeeze(pos_cost_state_space.x(1,:,:)) % reshape magic
xd1_pos = squeeze(pos_cost_state_space.xd(1,:,:)) % reshape magic


x1_vel = squeeze(vel_cost_state_space.x(1,:,:)) % reshape magic
xd1_vel = squeeze(vel_cost_state_space.xd(1,:,:)) % reshape magic


x1_un = squeeze(untunned_state_space.x(1,:,:)) % reshape magic
xd1_un = squeeze(untunned_state_space.xd(1,:,:)) % reshape magic



x2_all = squeeze(all_cost_state_space.x(2,:,:)) % reshape magic
xd2_all = squeeze(all_cost_state_space.xd(2,:,:)) % reshape magic


x2_pos = squeeze(pos_cost_state_space.x(2,:,:)) % reshape magic
xd2_pos = squeeze(pos_cost_state_space.xd(2,:,:)) % reshape magic


x2_vel = squeeze(vel_cost_state_space.x(2,:,:)) % reshape magic
xd2_vel = squeeze(vel_cost_state_space.xd(2,:,:)) % reshape magic



x2_un = squeeze(untunned_state_space.x(2,:,:)) % reshape magic
xd2_un = squeeze(untunned_state_space.xd(2,:,:)) % reshape magic


subplot(2,1,1);
hold on
plot(x1_all, xd1_all,'LineWidth',linewidth);
plot(x1_pos, xd1_pos,'LineWidth',linewidth);
plot(x1_vel, xd1_vel,'LineWidth',linewidth);
plot(x1_un, xd1_un,'LineWidth',linewidth);
title('Joint 1')
xlabel('$X$','interpreter','latex','FontSize',20)
ylabel('$\dot{X}$','interpreter','latex', 'rotation',0, 'FontSize',20)
legend('pos+vel cost','pos cost', 'vel cost', "untunned")


subplot(2,1,2);
hold on
plot(x2_all, xd2_all,'LineWidth',linewidth);
plot(x2_pos, xd2_pos,'LineWidth',linewidth);
plot(x2_vel, xd2_vel,'LineWidth',linewidth);
plot(x2_un, xd2_un,'LineWidth',linewidth);
title('Joint 2')
xlabel('$X$','interpreter','latex','FontSize', 30)
ylabel('$\dot{X}$','interpreter','latex', 'rotation', 0, 'FontSize',30)
legend('pos+vel cost','pos cost', 'vel cost', "untunned")

