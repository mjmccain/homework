%clear command window and workspace
clc
clear


% Create a randomized input vector and intialize a vector for prime numbers
inputVector = randi([1, 100], 1, 1000);

vectorMax = max(inputVector);
primesVector = [];

%loop over the random vector and pass each element as input to the function
for i = 1:length(inputVector)
    primesVector = [primesVector, findPrimes(inputVector(i))];
end

scatter(inputVector, primesVector, 'o','filled' )
hold on
%make a curve fit and plot it
%trend = fit([inputVector, primesVector], 'exp')
%plot(trend)
%use the curve fit to make a prediction for 2025 and plot it
title('The Nth Prime Numbers')
xlabel('Integer')
ylabel('Corresponding Prime')
grid on
