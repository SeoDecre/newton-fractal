function x = newton(p, x0)
    x = x0;
    px = horner(p, x0);
    p1 = derivata(p);
    while abs(px) > 1E-12
        x = x0 - horner(p, x0) / horner(p1, x0);
        px = horner(p, x);
        x0 = x;
    end
end
