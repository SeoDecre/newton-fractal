function y = horner(p, x)
    n = numel(p);
    res = p(1);
    for i = 2:n
        res = res*x + p(i);
    end
    y = res;
end
