<?php
interface Movable {

    function MoveUp($x,$y,$xspeed, $yspeed);
    function MoveDown($x,$y,$xspeed, $yspeed);
    function MoveLeft($x,$y,$xspeed, $yspeed);
    function MoveRight($x,$y,$xspeed, $yspeed);
}

class MovablePoint implements Movable {

private $x, $y, $xspeed, $yspeed;


    public function __construct($x,$y,$xspeed,$yspeed)
    {
        $this->x = $x;
        $this->y = $y;
        $this->xspeed = $xspeed;
        $this->yspeed = $yspeed;
    }

    public function getX()
    {
        return $this->x;
    }

    public function getY()
    {
        return $this->y;
    }

    public function getXspeed()
    {
        return $this->xspeed;
    }

    public function getYspeed()
    {
        return $this->yspeed;
    }




    public function MoveUp($x, $y, $xspeed,$yspeed){
        

    }
    public function MoveDown($x,$y,$xspeed, $yspeed){}
    public function MoveLeft($x,$y,$xspeed, $yspeed){}
    public function MoveRight($x,$y,$xspeed, $yspeed){}



        public function __toString(){
            $output = '';
            foreach($this->getX() as $xspeed){
                $output .= $xspeed;
            }
            return $output;
        }



}

$obj = new MovablePoint(1,2,3,2);
$obj->MoveUp(1,2,3,2);
$obj->MoveDown(1,2,3,2);
$obj->MoveLeft(1,2,3,2);
$obj->MoveRight(1,2,3,2);
