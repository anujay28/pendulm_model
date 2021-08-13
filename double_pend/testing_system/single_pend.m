
params = load('/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/fixed_model/test23/parameters23.mat')

% human parameters
way_points = [ 0 , -pi, 0;  0 -0.5*pi,0 ]

mh = [11.824, 3.848]; 
me = [ 2.11, 1.28]  + mh;

% other model params
lh = [0.324, 0.3900]
le = [0.324, 0.3900] 


% model 1 gains
Dm1 = [345.340576171875,0;0,146.162109375000];
Km1 = [402.030029296875,0;0,311.722412109375];





