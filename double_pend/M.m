function y = M(m, l, q)

y = [ (m(1)+m(2)) *l(1), m(2)*l(2)*cos(q(1)-q(2)); m(2)* l(1)*cos(q(1)-q(2)), m(2)*l(2)];

end
