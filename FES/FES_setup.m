

model.d_thr = [20; 20];
model.d_sat = [100; 100];
model.k_thr =  [100; 100];
model.k_sat =  [100; 100];
% 
model_bus_info = Simulink.Bus.createObject(model);
model_bus = evalin('base', model_bus_info.busName);

Tca = 0.04;
Tfat = 18;
Trec = 30;
freq = 30;
fit_min = 0;
beta =0.6;
d = [100, 100]

f = [100, 100]



lambda = 1 - beta + beta*(f./100)^2;
c3 = (a*fit_min*lambda)./Tfat + (1-a*lambda)./T_rec;
c4 = (a*lambda-1)./Trec - (a*lambda)/T_fat;
c5 = c3/c4;

fit = -c5+(1+c5)*exp(c4*t);

