using System;
using System.Collections.Generic;

namespace UnityBasic
{
    class Player
    {
        string strName;
        int nAttack;
        int nHP;
        public Player(string name,int atk, int hp)
        {
            strName = name;
            nAttack = atk;
            nHP = hp;
        }
        public void Attack(Player target)
        {
            target.nHP -= this.nAttack;
        }
        public bool Death()
        {
            if (nHP > 0) return false;
            else return true;
        }

        public void Show()
        {
            Console.WriteLine("###" + strName + "###");
            Console.WriteLine("HP:" + nHP);
            Console.WriteLine("Atk:" + nAttack);
        }
    }

    class Program
    {
        static void ClassBattleMain()
        {
            Player player = new Player("player",10,100);
            Player monster = new Player("slime",5,20);

            List<Player> listMonster = new List<Player>();
            listMonster.Add(monster);
            listMonster.Add(new Player("skeleton", 10, 50));
            listMonster.Add(new Player("zombie", 10, 50));
            listMonster.Add(new Player("dragon", 20, 200));

            while (true)
            {
                if (player.Death() == false)
                {
                    player.Attack(monster);
                    monster.Show();
                }
                else break;

                if (monster.Death() == false)
                {
                    monster.Attack(player);
                    player.Show();
                }
                else break;
            }
        }

        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            //ValMain();
            //PlayerAttackMonsterMain();
            //CriticalAttackMain();
            //StageMain();
            //ttackWhile();
            //BattleMain();
            ClassBattleMain();
        }

        static void ValMain()
        {
            int nScore = 0;
            float fRat = 1.0f / 4.0f;
            Console.WriteLine("Score:" + nScore);
            Console.WriteLine("Rat:" + fRat);
        }
        //플레이어가 몬스터를 공격한다.(단,몬스터의 hp는 100이고 플레이어의 공격력은 10이다)
        //(플레이어의 공격력:정수)만큼 (몬스터의 hp:정수)가 감소한다.
        //모든 변수들을 출력하여 해당결과가 정상적으로 작동하였는지 검증하는 것까지 마쳐야 한다.
        static void PlayerAttackMonsterMain()
        {
            int nPlayerAttack = 10;
            int nMonsterHP = 100;
            Console.WriteLine("1.MonsterHP:" + nMonsterHP);
            Console.WriteLine("1.PlayerAttack:" + nPlayerAttack);
            nMonsterHP = nMonsterHP - nPlayerAttack;
            Console.WriteLine("2.MonsterHP:" + nMonsterHP);
            Console.WriteLine("2.PlayerAttack:" + nPlayerAttack);
        }
        //플레이어가 몬스터를 확률적으로 추가데미지(일정비율로 증가)가 발생하는 공격한다.
        //확률적? 난수, 랜덤 과 같은 키워드로 검색하여 문법을 찾는다.
        static void CriticalAttackMain()
        {
            int nPlayerAttack = 10;
            int nMonsterHP = 100;
            Console.WriteLine("1.MonsterHP:" + nMonsterHP);
            Console.WriteLine("1.PlayerAttack:" + nPlayerAttack);
            Random cRandom = new Random();
            int nRandom = cRandom.Next(4);//ex) Next(4),Next(0,3)-0,1,3 / Next(1,3) - 1,2
            Console.WriteLine("Rondom:"+nRandom);
            if (nRandom == 1)
            {
                nMonsterHP = nMonsterHP - nPlayerAttack * 2;
            }
            else
            {
                nMonsterHP = nMonsterHP - nPlayerAttack;
            }
            Console.WriteLine("2.MonsterHP:" + nMonsterHP);
            Console.WriteLine("2.PlayerAttack:" + nPlayerAttack);
        }
        //텍스트게임에서 이동할 장소를 입력받아, 해당 장소에 따라 출력하도록 만들기
        //1. 입력받은 변수를 문장을 변수에 저장한다.
        //2. 저장된 변수의 값에 따라 어떤 장소인지 판단한다.
        //3. 해당장소인것이 판단되면 출력하여 어디인지 알려준다.
        static void StageMain()
        {
            Console.WriteLine("이동할 장소를 입력하세요.(마을,필드,상점)");
            string strInput = Console.ReadLine();

            switch(strInput)
            {
                case "마을":
                    Console.WriteLine("마을 입니다.");
                    break;
                case "필드":
                    Console.WriteLine("필드 입니다.");
                    break;
                case "상점":
                    Console.WriteLine("상점 입니다.");
                    break;
                default:
                    Console.WriteLine("이동 할 수 없는 장소입니다.");
                    break;
            }
        }
        //플레이어가 몬스터를 공격한다 죽을때까지 -> hp가 0이되면
        static void AttackWhile()
        {
            int nPlayerAttack = 15;
            int nMonsterHP = 100;
            Console.WriteLine("1.MonsterHP:" + nMonsterHP);
            Console.WriteLine("1.PlayerAttack:" + nPlayerAttack);
            //while (true)
            while (nMonsterHP > 0) //100 <= 0 -> 거짓 //몬스터의 hp가 0보다 클떄 -> 몬스터가 살아있을때
            {
                //if (nMonsterHP <= 0) break; //몬스터의 hp가 0작거나 같을때 -> 몬스터가 죽었을때
                nMonsterHP = nMonsterHP - nPlayerAttack;
                Console.WriteLine("2.MonsterHP:" + nMonsterHP);
                Console.WriteLine("2.PlayerAttack:" + nPlayerAttack);
            }
        }
        //플레이어가 몬스터를 공격한다.
        //(플레이어의 공격력:정수)만큼 (몬스터의 hp:정수)가 감소한다.
        //몬스터가 플레이어에게 반격한다.
        //(몬스터의 공격력:정수)만큼 (플레이어의 hp:정수)가 감소한다.
        //둘중하나가 죽을때까지 반복한다. -> 둘중하나가 죽으면 끝난다.
        //몬스터가 죽었지만 플레이어를 공격해서 플레이어가 사망했다 -> 죽으면 공격할수없다.
        static void BattleMain()
        {
            int nPlayerHP = 100;
            int nPlayerAttack = 10;
            int nMonsterHP = 100;
            int nMonsterAttack = 10;

            Random cRandom = new Random();

            Console.WriteLine("1.MonsterHP:" + nMonsterHP);
            Console.WriteLine("1.MonsterAttack:" + nMonsterAttack);

            Console.WriteLine("1.PlayerHP:" + nPlayerHP);
            Console.WriteLine("1.PlayerAttack:" + nPlayerAttack);
            //판단이 어려울땐 고민하지말고, 결과의 유효성을 적어서 검증한다.
            //10 > 0 -> 참  || 0 > 0 -> 거짓 -> 참
            //10 > 0 -> 참  && 0 > 0 -> 거짓 -> 거짓
            while (nPlayerHP > 0 && nMonsterHP > 0)
            {
                //if (nPlayerHP <= 0 || nMonsterHP <= 0) break;

                if (nPlayerHP > 0)
                {
                    //플레이어가 공격한다.
                    Console.WriteLine("Player Attack!");
                    
                    int nRandom = cRandom.Next(4);//ex) Next(4),Next(0,3)-0,1,3 / Next(1,3) - 1,2
                    Console.WriteLine("Rondom:" + nRandom);
                    if (nRandom == 1)
                    {
                        nMonsterHP = nMonsterHP - nPlayerAttack * 2;
                        Console.WriteLine("Critical!!!");
                    }
                    else
                    {
                        nMonsterHP = nMonsterHP - nPlayerAttack;
                    }
                    Console.WriteLine("2.MonsterHP:" + nMonsterHP);
                    Console.WriteLine("2.PlayerAttack:" + nPlayerAttack);
                }
                //else break;

                if (nMonsterHP > 0)
                {
                    //몬스터가 반격한다.
                    Console.WriteLine("Monster Attack!");
                    nPlayerHP = nPlayerHP - nMonsterAttack;
                    Console.WriteLine("2.PlayerHP:" + nPlayerHP);
                    Console.WriteLine("2.MonsterAttack:" + nMonsterAttack);
                }
                //else break;
            }
        }
        //몬스터의 리스트를 만들고, 첫번째값과 마지막값을 출력하고, 모든 리스트의 값을 출력한다.(단, 슬라임,스켈레톤,좀비,드래곤)
        static void MonsterListMain()
        {
            List<string> listMonsters = new List<string>();
            listMonsters.Add("Slime");
            listMonsters.Add("Skeleton");
            listMonsters.Add("Zombie");
            listMonsters.Add("Dragon");

            Console.WriteLine(listMonsters[0]);
            Console.WriteLine(listMonsters[3]);

            for (int i = 0; i < listMonsters.Count; i++)
                Console.WriteLine(i + ":" + listMonsters[i]);
        }
    }
}
