<?php

class SolutionsTest extends PHPUnit_Framework_TestCase
{

  private $s;
  function SolutionsTest() 
  {
    $this->s = new Solutions();
  }

  /**
   * @strict
   * @small
   */
  public function testProblem1()
  {
    $this->assertEquals(233168, $this->s->Problem1());
  }

  /**
   * @strict
   * @small
   */
  public function testProblem2() 
  {
    $this->assertEquals(4613732, $this->s->Problem2());
  }

  /**
   * @strict
   * @small
   */
  public function testProblem3() 
  {
    $this->assertEquals(6857 , $this->s->Problem3());
  }

  /**
   * @strict
   * @small
   */
  public function testProblem4() 
  {
    $this->assertEquals(906609 , $this->s->Problem4());
  }

  /**
   * @strict
   * @small
   */
  public function testProblem5() 
  {
    $this->assertEquals(232792560, $this->s->Problem5());
  }

  /**
   * @strict
   * @small
   */
  public function testProblem6() 
  {
    $this->assertEquals(25164150, $this->s->Problem6());
  }

  /**
   * @strict
   * @small
   */
  public function testProblem7() 
  {
    $this->assertEquals(104743, $this->s->Problem7());
  }

  /**
   * @strict
   * @small
   */
  public function testProblem8() 
  {
    $this->assertEquals(23514624000, $this->s->Problem8());
  }

  /**
   * @strict
   * @small
   */
  public function testProblem9() 
  {
    $this->assertEquals(31875000, $this->s->Problem9());
  }
}
