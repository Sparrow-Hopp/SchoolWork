using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class GameManager : MonoBehaviour
{
    public static GameManager singleton; //this declares an instance of GameManager, allowing GameManager to always exist
    public GameObject[] enemyArray; //create an array of enemy prefabs
    public List<GameObject> activeEnemyList; //Create a list (built later from the above array) to store enemies
    GameObject[] totalHealthArray;
    int totalHealth;
    int currentTotalHealthArrayIndex = 0;
    void Awake() //Awake runs quite early in the game initialization process, ensuring that GameManager will exist before needed by other objects
    {
        singleton = this; //initialize the singleton with this object. 
    }
    // Start is called before the first frame update
    void Start()
    {
        enemyArray = GameObject.FindGameObjectsWithTag("Enemy"); //load up enemyArray with any objects tagged "Enemy"
        InitEnemies();
        totalHealth = Health.maxPlayerHealth = Health.currentPlayerHealth = InitHealth(); //assign all total health values at once
        Debug.Log(totalHealth);
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
    public int InitHealth() //initialize health variables, array and return accumulator value
    {
        int accumulator = 0;
        totalHealthArray = GameObject.FindGameObjectsWithTag("Heart"); //load up totalHealthArray with any objects tagged "Heart"
        //iterate over all hearts and sum maxHealth
        for (int i = 0; i < totalHealthArray.Length; i++)
        {
            accumulator += totalHealthArray[i].GetComponent<Heart>().maxHealth; //accumulate all maxHealth values
            Debug.Log(totalHealthArray[i].GetComponent<Heart>().name);
        }
        return accumulator;
    }
    public void UpdateHealth(int damage = 0) //notice the inline initialization of damage to zero!
    {
        // Unity's Hierarchy will return the order of objects as set in the Hierarchy
        // so iterating over an array will result in the same sequence as shown top-to-bottom in the hierarchy.
        // reordering objects in the Hierarchy will also reorder them in the array totalHealthArray[].
        if (Health.currentPlayerHealth > 0)
        {
            if (currentTotalHealthArrayIndex < totalHealthArray.Length)
            {
                if (totalHealthArray[currentTotalHealthArrayIndex].GetComponent<Heart>().currentHealth > 0) //this test must not be evaluated with an out of bounds index
                {
                    totalHealthArray[currentTotalHealthArrayIndex].GetComponent<Heart>().Damage(damage);
                }
                else if (currentTotalHealthArrayIndex < totalHealthArray.Length)
                {
                    currentTotalHealthArrayIndex++;
                    UpdateHealth(); //notice this example of recursion is not in a recursive loop!
                }
            }
            // this function needs to update the total health variable: totalHealth
            totalHealth -= damage;
            Health.currentPlayerHealth = totalHealth;
        }
    }
}