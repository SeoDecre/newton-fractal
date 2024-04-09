function dp = derivata(p)
    if isempty(p) || numel(p) == 1
        dp = 0;
        return;
    end
    
    n = length(p) - 1; % Grado del polinomio originale
    dp = zeros(1, n); % Vettore dei coefficienti della derivata
    for i = 1:n
        dp(i) = p(i) * (n - i + 1);
    end
end
