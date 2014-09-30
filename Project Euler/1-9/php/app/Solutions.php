<?php

class Solutions 
{
    private function prime_values($limit) {
        // Sieve of erathosthenes implementation
        $range = range(2, $limit);
        $primes = array_combine($range, $range);
        $num = 2;

        while ($num*$num < $limit) {
            for ($i = 2*$num; $i <= $limit; $i += $num) {
                unset($primes[$i]);
            }
            $num = next($primes);
        }

        reset($primes);
        return $primes;
    }

    private function prime_factors($limit) {
        $factors = array();
        $primes  = array();
        $num = 2;

        for ($i = 2; $i < $limit+1; $i++) {
            if (!in_array($i, $factors) and $limit % $i === 0) {
                array_push($primes, $i);
          
                // $factors = $factors + range($i*$i, $limit, $i);
                // This doesn't work since it merges by key values favoring the left hand side;
                // In other words
                // {1, 2} + {3, 4, 5} = {1, 2, 4}

                // The following is proper merging
                $factors = array_unique(array_merge($factors, range($i*$i, $limit, $i)));
            }
        }

        return $primes;
    }

    function Problem1()
    {
        $sum = 0;
        $n = 1000;
        for ($i = 0; $i < $n; $i++) {
            if ($i % 3 === 0) {
                $sum += $i;
            }
            else if ($i % 5 === 0) {
                $sum += $i;
            }
        }

        return $sum;
    }

    function Problem2() 
    {
        $sum = 0;
        $a = 0;
        $b = 1;
        while ($b < 4000000) {
            if ($b % 2 == 0) {
                $sum += $b;
            }
            $temp = $a;
            $a = $b;
            $b = $temp + $b;
        }
        return $sum;
    }

    function Problem3()
    {
        $primes = $this->prime_values(100000);
        $n = 600851475143;
        $i = 0;
    
        while ($n > 1) {
            if ($n % current($primes) === 0) {
                $n /= current($primes);
            }
            else {
                next($primes);
            }
        }
        return current($primes);
    }

    function Problem4()
    {
        $max = 0;
        for ($i = 999; $i > 100; $i--) {
            for ($j = 999; $j > 100; $j--) {
                if ($i*$j < $max) {
                    break;
                }
                if (strval($i*$j) === strrev(strval($i*$j)) and $i*$j > $max) {
                    $max = $i*$j;
                }
            }
        }
        return $max;
    }

    function Problem5()
    {
        $n = 20;
        $max_prime_factors = array();
        $max_prime_powers  = array();

        for ($i = 1; $i <= $n; $i++) {
            $factors = $this->prime_factors($i);
            for ($j = 0; $j < count($factors); $j++) {
                $factor = $factors[$j];
                $power = 0;

                $temp = $i;
                while ($temp % $factor === 0) {
                    $power++;
                    $temp /= $factor;
                }

                if (in_array($factor, $max_prime_factors)) {
                    $index = array_search($factor, $max_prime_factors);
                    if ($max_prime_powers[$index] < $power) {
                        $max_prime_powers[$index] = $power;
                    }
                }
                else {
                    array_push($max_prime_factors, $factor);
                    array_push($max_prime_powers, $power);
                }
            }
        }

        $result = array_map(function ($a, $b) {
            return pow($a,$b);
        }, $max_prime_factors, $max_prime_powers);

        return array_product($result);
    }

    function Problem6()
    {
        $sum = 0;
        $n = 100;
        for ($i = 0; $i <= $n; $i++) {
            for ($j = $i+1; $j <= $n; $j++) {
                $sum += $i*$j;
            }
        }
        return 2*$sum;
    }

    function Problem7()
    {
        return 0;
    }

    function Problem8()
    {
        return 0;
    }

    function Problem9()
    {
        return 0;
    }
}
