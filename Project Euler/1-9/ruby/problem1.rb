#!/usr/bin/env ruby
# encoding: utf-8

def calculate_sum_from_zero(num, step)
  x = num / step
  return (x * (x + 1) / 2) * step
end

puts calculate_sum_from_zero(999, 3) + calculate_sum_from_zero(999, 5) - calculate_sum_from_zero(999, 15)
