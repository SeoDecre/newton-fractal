function img = newtonfractal(dim)
    img = zeros(dim);
    range = linspace(-2, 2, dim);
    p = [1, 0, 0, 1];
    for k = 1:dim
        for j = 1:dim
            z0 = range(k) + range(j)*1i;
            n = newton(p, z0);
            img(k, j) = decidi(n);
        end
    end
end