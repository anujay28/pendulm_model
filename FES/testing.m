


tau = zeros(9,1);

ma = rand(9,3)

dtheta = [ 1 2 3]

for ii = 1:3
  for jj = 1:9
      tau(jj) = tau(jj) + dtheta(ii) * ma(jj,ii);
  end
end

tau
