#!/usr/bin/env ruby
# encoding: utf-8

def prime_factors(n)
  factors = {}
  c = 2
  while n != 1
    if n % c == 0
      factors[c] = 0
      while n % c == 0
        n /= c
        factors[c] += 1
      end
    else
      c += 1
    end
  end

  factors
end

k = 20
current = {}

for i in 1..k
  current.merge!(prime_factors(i)){ |a, b, c| [b, c].max }
end

sum = 1
current.each_pair do |x, y|
  sum *= x ** y
end

puts sum
