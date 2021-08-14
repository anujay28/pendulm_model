mylinewidth = 2

filename = '/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/modifed_model/tests/none/exo_torque.fig'
fig = openfig(filename);

ax = fig.CurrentAxes
g_array = ax.Children
x = g_array(1).XData

exo_joint1 = g_array(1).YData
exo_joint2 = g_array(2).YData


filename = '/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/modifed_model/tests/none/human_torque.fig'
fig = openfig(filename);

ax = fig.CurrentAxes
g_array = ax.Children
x = g_array(1).XData

human_joint1 = g_array(1).YData
human_joint2 = g_array(2).YData


filename = '/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/modifed_model/tests/none/joint1_traj.fig'
fig = openfig(filename);

ax = fig.CurrentAxes
g_array = ax.Children
x = g_array(1).XData

ref1 = g_array(1).YData
human_joint_traj1 = g_array(2).YData
exo_joint_traj1 = g_array(3).YData


filename = '/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/modifed_model/tests/none/joint2_traj.fig'
fig = openfig(filename);

ax = fig.CurrentAxes
g_array = ax.Children
x = g_array(1).XData

ref2 = g_array(1).YData
human_joint_traj2 = g_array(2).YData
exo_joint_traj2 = g_array(3).YData

close all



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

t = linspace(0, 100, length(human_joint1));

% 
% figure(1)
% hold on;
% plot(t,human_joint1,'linewidth',mylinewidth);
% plot(t,human_joint2,'linewidth',mylinewidth);
% plot(t,exo_joint1,'linewidth',mylinewidth);
% plot(t,exo_joint2,'linewidth',mylinewidth);
% legend("assistie joint1","assistie joint2","assistor joint1","assistor joint2");
% title('Torque Comparison for no effort supplied by assistie');
% xlabel('$Gait \%$','interpreter','latex','FontSize',20);
% ylabel('$\tau$ (Nm)','interpreter','latex', 'rotation',0, 'FontSize',20);





% filename = '/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/modifed_model/tests/none/joint1.fig'
% fig = openfig(filename);
% 
% ax = fig.CurrentAxes
% g_array = ax.Children
% x = g_array(1).XData
% 
% human_joint1 = g_array(1).YData
% human_joint2 = g_array(2).YData
% 
% 
% figure(2)
% 
% subplot(2,1,1);
% hold on;
% plot(t,rad2deg(ref1),'linewidth',mylinewidth);
% plot(t,rad2deg(human_joint_traj1),'linewidth',mylinewidth);
% plot(t,rad2deg(exo_joint_traj1),'linewidth',mylinewidth);
% 
% legend("ref","assistie","assistor");
% title('Joint 1');
% xlabel('$Gait \%$','interpreter','latex','FontSize',20);
% ylabel('$\theta (deg)$','interpreter','latex', 'rotation',0, 'FontSize',20);
% 
% subplot(2,1,2);
% hold on;
% plot(t,rad2deg(ref2),'linewidth',mylinewidth);
% plot(t,rad2deg(human_joint_traj2),'linewidth',mylinewidth);
% plot(t,rad2deg(exo_joint_traj2),'linewidth',mylinewidth);
% legend("ref","assistie","assistor");
% title('Joint 2');
% xlabel('$Gait \%$','interpreter','latex','FontSize',20);
% ylabel('$\theta (deg)$','interpreter','latex', 'rotation',0, 'FontSize',20);


error_human_joint1 = sqrt(sum((rad2deg(ref1) - rad2deg(human_joint_traj1)).^2 )/length(human_joint_traj1))
error_human_joint2 = sqrt(sum((rad2deg(ref2) - rad2deg(human_joint_traj2)).^2 )/length(human_joint_traj2))

error_exo_joint1 = sqrt(sum((rad2deg(ref1) - rad2deg(exo_joint_traj1)).^2 )/length(exo_joint_traj1))
error_exo_joint2 = sqrt(sum((rad2deg(ref2) - rad2deg(exo_joint_traj2)).^2 )/length(exo_joint_traj2))



