let sentence = "The dog chased the cat.";
let myregex = /cat/;
let result = myregex.test(sentence);
console.log(result);

let petString = "James has a pet cat.";
let petRegex = /dog|cat|bird|fish/;
let resultPet = petRegex.test(petString);
console.log(resultPet);

let flagString = "James has a pet cat.";
let fccRegex = /dog|cat|bird|fish/;
let resultFlag = petRegex.test(petString);
console.log(resultPet);

//period "."
let humStr = "I'll hum a song";
let husStr = "I'll sing a song in Oahu";
let hugStr = "Bear hug";
let huRegex = /hu./;
let husRegex = /.hu/;

console.log(humStr.match(huRegex));
console.log(husStr.match(husRegex));

//predefine group of characters
let groupString = "Beware of bugs in the above code; I have only";
let gRegex = /b[aiu]gs/g;
let resultGroup = groupString.match(gRegex);
console.log(resultGroup);

//all of the same group characters
let allString = "Beware of bugs in the above code; I have only";
let allLettersRegex = /[a-z]/ig;
let resoultAll = allString.match(allLettersRegex);
console.log(resoultAll);

//all of the same group characters combined
let combString = "Raspberry 3.14159265 are delicious.";
let combRegex = /[a-z1-8]/ig;
let resoultComb = combString.match(combRegex);
console.log(resoultComb);

//negated character sets
//returns everything except regex
let negString = "3 Blind mice.";
let negRegex = /[^0-9aeiou]/ig;
let negResult = negString.match(negRegex);
console.log(negResult);

//match characters that occur one or more times
let chString = "Mississipi Queens!";
let chRegex = /s+/g;
let chResult = chString.match(chRegex);
console.log(chResult);

//match characters that occur one or more times
//returns 'g' or 'go' or 'goo' or ...
let gString = "goooooooooooal!";
let g2String = "gut feelings";
let g3String = "over the moon";
let goRegex = /go*/g;
let gResult = gString.match(goRegex);
let g1Result = g2String.match(goRegex);
let g2Result = g3String.match(goRegex);
console.log(gResult);
console.log(g1Result);
console.log(g2Result);

//find characters with lazy matching
let titanic = "titanic "

