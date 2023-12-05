%Marcus McCain
%Project 2
% This code finds the nth Prime number and graphs it.

%clear command window and workspace
clc
clear

% Create a randomized input vector and intialize a vector to store prime numbers
inputVector = randi([1, 100], 1, 1000);
primesVector = [];

%loop over the randomized vector and pass each element as input to the function
%The functions output is concatenated to primesVector
for i = 1:length(inputVector)
    primesVector = [primesVector, findPrimes(inputVector(i))];
end

%Make a trendline that fits the data, then plot the trendline and data
[trendline, gof] = fit(inputVector', primesVector', 'poly2')
plot(trendline,inputVector, primesVector)

%Make the graph look nice. Add title, labels, legend, and grid.
title('The Nth Prime Numbers',FontSize=16)
xlabel('Nth-Integer', FontSize=16)
ylabel('Corresponding Prime', FontSize=16)
legend('Primes data', 'Trendline', 'Location', 'Northwest',FontSize=16)
grid on
