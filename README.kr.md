### What is "pattern matcher"?
+ �ΰ��� ������ ��. ù��° ������ �����̰� �ι�°�� �񱳴�� �����̴�. 
+ ���� ���ϰ� �񱳴�� ������ �Ⱦ ���� ��� ������ ������ ã�´�.
+ ������ ������ �ν����� �ʴ´�. �������� �������� �������� �ν�. (ex3)
+ ��ū ���ؿ��� ������ �м��Ѵ�. 
  ��ū�� ���ڳ� ���ĺ����� �̷��� ���ڿ��̰ų� Ư�� �����̴�. ���� ���ڴ� ��ū�� �� �� ����. (ex4)
  
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
  + �� ��ġ ������ �����ش�.
  + ������ ��ġ�� ���ؼ� ���� ��� ������ ������ ��µȴ�. 
  + ������ ���ϵ鿡 ���ؼ� �ش� ������ ������ ��������� ��ġ�ϴ��� �����ش�. 
  + ��ȣ ���� ���ڴ� ù��°, ������ ��ū�� ù��° ������ ����ȣ, ���ȣ�� ����Ų��. 
   
### Feedback 
  contact (hooo.dev@gmail.com)