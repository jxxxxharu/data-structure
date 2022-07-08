# Chapter 03. 순차 리스트 (= 배열 기반 리스트)

배열을 기반으로 리스트(List) 구현하기


## 리스트의 ADT

* void ListInit(List* plist); 
	- 리스트 초기화 (OOP의 생성자 같은 것)

* void LInsert(List* plist, LData data);
	- 리스트 끝에 데이터 추가

* int LFirst(List* plist, LData* data);
	- (참조위치) = 0으로 초기화
	- 참조를 앞에서부터 새로 시작하기 위해 호출한다
	- 참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환

* int LNext(List* plist, LData* data);
	- 순차적인 참조를 위해 (참조위치)++
	- 참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환

* int LRemove(List* plist, LData* data);
	- LFirst()나 LNext()를 통해 바로 직전 참조된 데이터를 삭제
	- 삭제된 데이터 반환

* int LCount(List* plist, LData* data);
	- 리스트에 저장된 데이터의 수 반환



### 삽입과 조회
LFirst -> LNext -> LNext -> LNext -> ...
=> 보편적인 데이터 참조 모델이다.


### 삭제
삭제의 기본 모델 - 중간에 데이터가 삭제 시, 뒤에 저장된 데이터들을 앞으로 한 칸씩 이동시킴


### 장점
- 배열을 이용하기 때문에 데이터 참조가 쉽다. 인덱스 값을 기준으로 어디든 한 번에 참조가 가능하다.

### 단점
- 배열 길이가 초기에 결정되고, 변경이 불가능하다.
- 삭제 과정에서 데이터의 이동(복사)이 발생한다.