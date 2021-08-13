
params = load('/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/fixed_model/test25/parameters.mat')

% human parameters
way_points = [ 0 , -pi, 0;  0 -0.5*pi,0 ]

mh = [11.824, 3.848]; 
me = [ 2.11, 1.28]  + mh;

% other model params
lh = [0.324, 0.3900]
le = [0.324, 0.3900] 



myQ = diag([.1 10 0.001 0.001]);
myR = diag([0.001 0.001 0.00 0.00]);


% connection dyamics
spring = [100, 0; 0, 100];
dampener = [100, 0; 0, 100];


% model 1 gains
Km1 = [300, 0; 0 300];
Dm1 = [300,0;0,300];

Dm1 = [345.340576171875,0;0,146.162109375000];
Km1 = [402.030029296875,0;0,311.722412109375];

Dm1 = [1000,0;0,103.228187679703];
Km1 = [1000,0;0,1000]


% Addmittance Controller
Kd = [50,0;0, 50];
Bd = [50,0;0, 50];
Md = [10.0, 0; 0, 10.0];


%Works well with the lower masses
lambda2 = params.test_25(6,1).Value;
rho2 = params.test_25(8,1).Value;
exo_sat = 0.0;
human_sat = 150;
beta = params.test_25(5,1).Value;


Kem = [ 50, 0; 0, 50];
Ked = [ 50, 0; 0, 50];


Kp0 = params.test_25(4,1).Value;
Kn0 = params.test_25(3,1).Value;
Bp0 = params.test_25(2,1).Value;
Bn0 = params.test_25(1,1).Value;
alpha = params.test_25(7,1).Value;
gamma = params.test_25(9,1).Value;

