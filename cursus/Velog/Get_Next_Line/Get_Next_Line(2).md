# [42 Seoul] Get Next Line(2) - overview
Get Next Line 과제를 위해 생각해야하는 부분들에 대해 적은 글입니다.  

## get_next_line의 목적
- 주어진 file descriptor에 해당하는 file로부터 라인단위로 글을 읽어옵니다.  
- 한 번 호출때마다, 한 줄씩 글을 읽습니다.
- 읽기 성공하면 1, EOF에 다다르면 0, error가 발생하면 -1을 반환합니다.  

## Overview
1. 저는 static 변수인 backup을 기준으로 loop를 만들었습니다. 
2. backup에 '\n'이 있는 경우, '\n' 기준으로 앞, 뒤를 나누고,  
   앞은 line으로, 뒤는 새로운 backup으로 사용합니다.
3. backup에 '\n'이 없는 경우, '\n'을 발견할 때까지 계속해서 읽어와야합니다.  
   '\n'을 발견할 때까지 계속해서 backup에 읽은 값들을 붙여나갑니다.

## Detail
### split_lines 함수
: '\n'이 있는 경우입니다.
1. while문 조건 확인시 찾았던 next_line('\n'뒤를 가리키는)을 사용합니다.
2. line에 '\n' 이전 값을 할당하기 위해, next_line - *backup + 1의  
   크기를 가진 버퍼를 만들고 '\n' 이전 값을 복사합니다.
3. 이전에 가졌던 backup을 갱신하기 위해 new_backup에 new_line 이후 값을  
   넣습니다. 
4. 이때, new_backup이 NULL이 비어있다면, 메모리 누수를 막기위해 backup과  
   new_backup 모두 메모리를 해제시킵니다.

### keep_bufs 함수
: '\n'이 없는 경우에서 새로운 값을 읽었을 때, backup에 값을 저장해둡니다.  

1. 새로 갱신할 버퍼의 크기를 구하기 위해, 현재 backup, 읽어온 값(buf)의  
   길이를 더합니다. 
2. new_backup을 위한 메모리를 할당하고, backup과 buf의 값을 모두 나란히  
   복사합니다. 
3. 메모리 누수를 막기위해, 이전 backup값의 메모리 공간은 해제하고, 새로운  
   new_backup으로 갱신합니다. 