
PW = -10:1:550;

ar = recruitment(PW);

figure(1)

plot(PW,ar)
xlabel("PW")
ylabel("recruiment")
title("Pulse Width")


hip_angles = rad2deg(myjoints(25:end,5));
knee_angles = rad2deg(myjoints(25:end,6));
ankle_angles = rad2deg(myjoints(25:end,7));

ma = zeros(9,3, length(hip_angles)-1);

% % 
for ii = 1:length(hip_angles)
    
  ma(:,:,ii) = calc_ma([hip_angles(ii),...
                        knee_angles(ii), ...
                        ankle_angles(ii)]);

end

figure(2)
hold on
for ii=1:9
    thing = reshape(ma(ii,1,:),1,[]); 
    plot(hip_angles, thing);
end
title("hip ma");


figure(3)
hold on
for ii=1:9
    thing = reshape(ma(ii,2,:),1,[]); 
    plot(knee_angles, thing);
end
title("knee ma");

figure(4)
hold on
for ii=1:9
    thing = reshape(ma(ii,3,:),1,[]); 
    plot(ankle_angles , thing);
end
title("ankle ma");


elastic_torques = zeros(3, length(hip_angles)-1);

for ii = 1:length(hip_angles)
    
 torques = elastic([hip_angles(ii),...
                        knee_angles(ii), ...
                        ankle_angles(ii)]);
        
  elastic_torques(:,ii) = torques;
end

figure(5)
hold on
t = linspace(1,100, length(hip_angles));
plot(t, elastic_torques(1,:))
plot(t, elastic_torques(2,:))
plot(t, elastic_torques(3,:))


my_dma = zeros(9,3, length(hip_angles));

init_ma = calc_ma([0,0,0]);
% % 

prev_ma = init_ma;


for ii = 1:length(hip_angles)
   [k1 ddma] = dma(prev_ma, [hip_angles(ii),...
                             knee_angles(ii), ...
                              ankle_angles(ii)]);
    prev_ma = ddma;
    my_ma(:,:,ii) = ddma;
end

figure(6)
hold on
for ii=1:9
    thing = reshape(my_ma(ii,3,:),1,[]); 
    plot(ankle_angles, thing);
end
title("knee dma");

