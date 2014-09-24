<?php

class SolutionsTest extends PHPUnit_Framework_TestCase
{
  /**
   * @strict
   * @small
   */
  public function testProblem1()
  {
    $s = new Solutions();
    $this->assertEquals(233168, $s->problem1());
  }
}
