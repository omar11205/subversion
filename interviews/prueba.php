<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
    <?php

        function classifyAttendances($concepts, $attendanceIn, $attendanceOut){
            $decoded = json_decode($concepts, true);
            $classify = array();
            $startAtt = DateTime::createFromFormat('H:i', $attendanceIn);
            $endAtt = DateTime::createFromFormat('H:i', $attendanceOut);

            //si la hora de entrada del trabajador es mayor que la de salida agregar un día a la hora de salida
            if ($endAtt < $startAtt){
                $endAtt->modify('+1 day');
            }
            
            //pasar de string "HH:mm" a DateTime las horas de los conceptos dentro del array $decoded
            foreach($decoded as &$concept){
                $concept['start'] = DateTime::createFromFormat('H:i', $concept['start']);
                $concept['end'] = DateTime::createFromFormat('H:i', $concept['end']);

                //si el fin del concepto es menor que el inicio del concepto agregar un día al fin del concepto
                if ($concept['end'] < $concept['start']){
                    $concept['end']->modify('+1 day');
                }
            }
            unset($concept);

            //ordenar de menor a mayor los conceptos de $decoded según la hora de inicio del concepto
            $startSortTimes = array_column($decoded, 'start');
            array_multisort($startSortTimes, SORT_ASC, $decoded);

            foreach($decoded as $concept){
                //filtra el/los intervalo(s) de tiempo de concepto(s) donde está contenido el intervalo de tiempo trabajado (endAtt - startAtt)
                if($startAtt <= $concept['end'] && $endAtt >= $concept['start']){
                    //determina el tiempo que se ha trabajado por cada concepto como la diferencia entre: el mínimo de entre la hora de salida y la hora de fin del concepto, y el máximo de entre la hora de entrada y la hora de comienzo del concepto
                    $dateDiff = min($concept['end'], $endAtt)->diff(max($concept['start'], $startAtt));
                    $hours = $dateDiff->h;
                    $minutes = $dateDiff->i;
                    $float = $hours + $minutes/60;
                    $rounded = round($float, 1); 
                    $classify[$concept['name']] = $rounded;
                } 
            }

            return json_encode($classify);

        }


        class Concept {
            public $id;
            public $name;
            public $start;
            public $end;
           
            public function __construct($id, $name, $start, $end){
                $this->id = $id;
                $this->name = $name;
                $this->start = $start;
                $this->end = $end;
            }
            public function toArray(){
                $myArray = array("id"=>$this->id, "name"=>$this->name,"start"=>$this->start, "end"=>$this->end);
                return $myArray;
            }
    
        }
        
        $HOConcept = new Concept("HO", "HO", "08:00", "11:59");//horas ordinarias de la mañana
        $HAConcept = new Concept("HA", "HA", "12:00", "13:59");//horas de almuerzo
        $HOTConcept = new Concept("HOT", "HOT", "14:00", "17:59");//horas ordinarias de la tarde
        //$HOConcept = new Concept("HO", "HO", "08:00", "17:59");//horas ordinarias
        $HEDConcept = new Concept("HED", "HED", "18:00", "20:59");//horas extras diurnas
        $HENConcept = new Concept("HEN", "HEN", "21:00", "05:59");//horas extras nocturnas

        $HO_array = $HOConcept->toArray();
        $HA_array = $HAConcept->toArray();
        $HOT_array = $HOTConcept->toArray();
        $HED_array = $HEDConcept->toArray();
        $HEN_array = $HENConcept->toArray();


        $conceptsJSON = json_encode(array($HA_array, $HOT_array, $HED_array, $HEN_array, $HO_array), JSON_PRETTY_PRINT);
        //$conceptsJSON = json_encode(array($HO_array, $HED_array, $HEN_array), JSON_PRETTY_PRINT);

        echo "<pre>";
        print_r($conceptsJSON);
        echo "</pre>";

        echo "<pre>";
        print_r(classifyAttendances($conceptsJSON, '08:00', '15:30'));
        echo "</pre>";
    ?>
    
</body>
</html>