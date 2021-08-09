function [] = play_file(params_file) 
    params = load(file)

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
    lambda2 = params.test_16.Value(6,1);;
    rho2 = params.test_16.Value(8,1);;
    exo_sat = 150;
    human_sat = 30;
    beta = params.test_16.Value(5,1);


    Kem = [ 50, 0; 0, 50];
    Ked = [ 50, 0; 0, 50];


    Kp0 = params.test_16.Value(4,1);
    Kn0 = params.test_16.Value(3,1);
    Bp0 = params.test_16.Value(2,1);
    Bn0 = params.test_16.Value(1,1);
    alpha = params.test_16.Value(7,1);
    gamma = params.test_16.Value(9,1);

end