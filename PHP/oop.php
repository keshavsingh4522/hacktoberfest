<?php

class Person {

    public $name ;

    public $state = "stand";


    public function __construct($name){

        $this->name = $name;

    }

    public function run(){

        $this->state = "Running";

        echo $this->name . " " . "is" . " " . $this->state;

    }
}

$person = new Person("Mr Robot");
$person->run();


?>