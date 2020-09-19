using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Collections.Generic;

public class GameManager : MonoBehaviour
{
    public static GameManager singleton; //this declares an instance of GameManager, allowing GameManager to always exist
    public GameObject[] enemyArray; //create an array of enemy prefabs
    public List<GameObject> activeEnemyList; //Create a list (built later from the above array) to store enemies
    // Start is called before the first frame update
    void Start()
    {
        enemyArray = GameObject.FindGameObjectsWithTag("Enemy"); //load up enemyArray with any objects tagged "Enemy" 
        InitEnemies();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void Awake() //Awake runs quite early in the game initialization process, ensuring that GameManager will exist before needed by other objects
    {
        singleton = this; //initialize the singleton with this object. 
    }

    void InitEnemies()
    {
        activeEnemyList = new List<GameObject>(); //the activeEnemyList needs to exist so that objects in the list can be removed (in C# a List is really a dynamic array)
        for (int i = 0; i < enemyArray.Length; i++)
        {
            activeEnemyList.Add(enemyArray[i]); //initialize the activeEnemyList with the enemyArray...
        }
    }

    public void UnlistEnemy(GameObject enemy)
    {
        for (int i = 0; i < activeEnemyList.Count; i++)
        {
            if (activeEnemyList[i] == enemy)
            {
                activeEnemyList.RemoveAt(i); //remove the clicked enemy from the List
                break;
            }
        }
        if (activeEnemyList.Count == 0)
        {
            StartCoroutine(ResetAllEnemies());
        }
    }

    IEnumerator ResetAllEnemies()
    {
        yield return new WaitForSeconds(2);
        for (int i = 0; i < enemyArray.Length; i++)
        {
            enemyArray[i].GetComponent<Enemy>().Respawn();
            activeEnemyList.Add(enemyArray[i]);
        }
    }
}
