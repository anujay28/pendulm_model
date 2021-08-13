function y = G(m, q)

    g = 9.81;                  % Needed in order to set variable class correctly

    y =[ (m(1)+m(2))*g*sin(q(1)); m(2)*g*sin(q(2))] ;

end

