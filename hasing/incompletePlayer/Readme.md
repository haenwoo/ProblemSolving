# 문제 설명<br>
#### 수 많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한명의 선수를 제외하고는 모든 선수가 마라톤을 완주함.  
#### 마라톤에 참여한 선수들의 이름이 담긴 배열 participant, 완주한 선수들의 이름이 담긴 배열 completion이 주어진다.
#### 이 때 완주하지 못한 선수의 이름을 return하도록 solution 함수를 작성하시오.<br><br><br>
# 제한 조건<br>
####
- 마라톤 경기에 참여한 선수의 수는 1명이상, 100,000명 이하  
- completion의 길이는 participant의 길이보다 1 작다.  
- 참가자의 이름은 1개 이상, 20개 이하의 알파벳 소문자로 이루어져 있다.
- 참가자 중에는 동명이인이 있을 수 있다.<br><br><br>
# 입출력 예  
| participant | completion | return |
---|:---|:---:
| ["leo", "kiki", "eden"] | ["eden", "kiki"] | "leo" |
| ["marina", "josipa", "nikola", "vinko", "filipa"] | ["josipa", "filipa", "marina", "nikola"] | "vinko" |
| ["mislav", "stanko", "mislav", "ana"] | ["stanko", "ana", "mislav"] | "mislav" |    <br><br>

##### 예제 #1 leo는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

##### 예제 #2 vinko는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

##### 예제 #3 mislav는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.
