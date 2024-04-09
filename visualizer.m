function v = visualizer()
    % Legge e visualizza la matrice dal file di testo
    matrice = dlmread('matrix.txt');
    imagesc(matrice);
end