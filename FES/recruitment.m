function [ a_r ] = recruitment(d, model)

   
    d_thr = model.d_thr;
    d_sat = model.d_sat;
    k_thr = model.k_thr;
    k_sat = model.k_sat;
    max_d = 999999999;
   

    n1 = (-d_thr).*atan(-k_thr.*d_thr) - (-d_sat).*atan(-k_sat.*d_sat);
    n2 = (max_d-d_thr).*atan(k_thr.*(max_d-d_thr)) - (max_d-d_sat).*atan(k_sat.*(max_d-d_sat));

    c1 = 1./(n2-n1);
    c2 = -n1./(n2-n1);
    a_r =  c1.*( (d-d_thr).*atan(k_thr.*(d-d_thr)) - (d-d_sat).*atan(k_sat.*(d-d_sat))) + c2;
end
