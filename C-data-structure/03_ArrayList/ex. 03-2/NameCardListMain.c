/* 리스트 활용 - 이름표 */
#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main() {
	List list;
	NameCard* pcard;
	ListInit(&list);
	
	// 1) 3명의 전화번호 정보를 리스트에 저장한다.
	pcard = MakeNameCard("JoEun Yang", "010-7221-7513");
	LInsert(&list, pcard);

	pcard = MakeNameCard("Monkey JuJu", "010-1111-2345");
	LInsert(&list, pcard);

	pcard = MakeNameCard("BoomBoomPow", "010-0000-0000");
	LInsert(&list, pcard);


	// 2) JoEun Yang의 정보를 출력한다.
	printf("--------------------------------\n\n");
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "JoEun Yang")) {
			ShowNameCardInfo(pcard);
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "JoEun Yang")) {
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}
	printf("--------------------------------\n\n");


	// 3) Monkey JuJu의 전화번호 정보를 변경한다.
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "Monkey JuJu")) {
			ChangePhoneNum(pcard, "010-9876-5432");
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "Monkey JuJu")) {
					ChangePhoneNum(pcard, "010-9876-5432");
					break;
				}
			}
		}
	}


	// 4) BoomBoomPow의 정보를 삭제한다.
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "BoomBoomPow")) {
			LRemove(&list);
			free(pcard);
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "BoomBoomPow")) {
					LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}


	// 5) 남아있는 모든 사람의 전화번호 정보를 출력한다.
	if (LFirst(&list, &pcard)) {
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard)) {
			ShowNameCardInfo(pcard);
		}
	}
	printf("--------------------------------\n\n");

	return 0;
}