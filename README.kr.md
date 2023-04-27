### What is "pattern matcher"?
+ 두개의 파일을 비교. 첫번째 파일이 메인이고 두번째는 비교대상 파일이다. 
+ 메인 파일과 비교대상 파일을 훑어서 가장 길게 동일한 문장을 찾는다.
+ 수정된 문장은 인식하지 않는다. 여러개로 나뉘어진 문장으로 인식. (ex3)
+ 토큰 수준에서 파일을 분석한다. 
  토큰은 숫자나 알파벳으로 이뤄진 문자열이거나 특수 문자이다. 공백 문자는 토큰이 될 수 없다. (ex4)
  
### How to use it?
  ./match [file1] [file2]

### Examples
1. ex1
  + file1 : ~~hello from the other~~ ~~side~~ at least there? 
  + file2 : hello hello from ~~side~~ hello from the ~~hello from the other~~ 
2. ex2
  + file1 : ~~hello from the~~ ~~other side~~
  + file2 : from the ~~other side~~ ~~hello from the~~
3. ex3
  + file1 : ~~hello~~ from ~~the other side~~
  + file2 : ~~hello~~ to ~~the other side~~
4. ex4
  + file1 : ~~hello $~~~~~~~~$ from the other side~~
  + file2 : ~~hello
            $~~~~~~~~~$from the other side~~

### Program Result
+ file1
  ~~hello from the other side
  hello from the~~ here ~~side
  I must have called a~~ hundred ~~times~~
+ file2
  ~~hello from the other side
  hello from the~~ other ~~side
  I must have called a~~ thousand ~~times~~
+ result![program result](./result.png)  
+ explanation 
  + 총 매치 개수를 보여준다.
  + 각각의 매치에 대해서 가장 길고 동일한 문장이 출력된다. 
  + 각각의 파일들에 대해서 해당 문장이 파일의 어느지점에 위치하는지 보여준다. 
  + 괄호 안의 숫자는 첫번째, 마지막 토큰의 첫번째 문자의 열번호, 행번호를 가리킨다. 
   
### Feedback 
  contact (hooo.dev@gmail.com)