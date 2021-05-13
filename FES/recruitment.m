function [ a_r ] = recruitment(d)

    d_thr = 122.0;
    d_sat = 487.0;
    k_thr = 0.02*10^6;
    k_sat = 0.00938*10^(6);
    max_d = 999999999;
   

    n1 = (-d_thr).*atan(-k_thr.*d_thr) - (-d_sat).*atan(-k_sat.*d_sat);
    n2 = (max_d-d_thr).*atan(k_thr.*(max_d-d_thr)) - (max_d-d_sat).*atan(k_sat.*(max_d-d_sat));

    c1 = 1./(n2-n1);
    c2 = -n1./(n2-n1);
    a_r =  c1.*( (d-d_thr).*atan(k_thr.*(d-d_thr)) - (d-d_sat).*atan(k_sat.*(d-d_sat))) + c2;
end
