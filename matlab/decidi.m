function val = decidi(x)
    [~, val] = min(abs([x + 1, x - (1/2 - sqrt(3)/2i), x - (1/2 + sqrt(3)/2i)]));
end