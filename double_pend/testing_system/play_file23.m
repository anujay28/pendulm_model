
params = load('/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/fixed_model/test23/parameters23.mat')

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
Km1 = [30, 0; 0 30];
Dm1 = [30,0;0,30];



% Addmittance Controller
Kd = [50,0;0, 50];
Bd = [50,0;0, 50];
Md = [10.0, 0; 0, 10.0];


%Works well with the lower masses
lambda2 = params.test_23(6,1).Value;
rho2 = params.test_23(8,1).Value;
exo_sat = 150;
human_sat = 200;
beta = params.test_23(5,1).Value;


Kem = [ 50, 0; 0, 50];
Ked = [ 50, 0; 0, 50];


Kp0 = params.test_23(4,1).Value;
Kn0 = params.test_23(3,1).Value;
Bp0 = params.test_23(2,1).Value;
Bn0 = params.test_23(1,1).Value;
alpha = params.test_23(7,1).Value;
gamma = params.test_23(9,1).Value;

