% Initialization
F = [3 5 4 4 4;5 5 2 6 6 ;5 2 6 6 6 ;6 7 5 5 3;3 5 2 4 4]
G = [0 -1 0;-1 4 -1;0 -1 0]
FxG = F;

% Convolution
[bf, kf] = size(F);
[bg, kg] = size(G);

m2 = floor(bg/2);
n2 = floor(kg/2);

for i = m2+1 : bf-m2;
    for j = n2+1 : kf-n2;
        temp = 0;
        for k = -m2: m2;
            for l = -n2: n2;
                temp = temp + G(k + m2+1,l+n2+1) * F(i-k,j-l);
            end
        end
        FxG(i,j) = temp;
    end
end

FxG = FxG(2:bf-1,2:kf-1)