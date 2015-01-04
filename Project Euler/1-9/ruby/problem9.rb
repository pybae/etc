#!/usr/bin/env ruby
# encoding: utf-8

for i in 1...10
  for j in 1...i
    a = i**2 - j**2
    b = 2*i*j
    c= i**2 + j**2
    if 1000 % (a+b+c) == 0
      factor = 1000/(a+b+c)
      puts [factor*a, factor*b, factor*c].reduce(:*)
    end
  end
end
