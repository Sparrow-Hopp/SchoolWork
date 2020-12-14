using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static int numOfEnemyTypes;
    public int [] xpReqs = new int [20];
    public GameObject [] enemy = new GameObject [numOfEnemyTypes];

    // GridManager will appear to be a public static class.
    private static GameManager instance;

    public GameObject player;

    public int health;
    public static int playerLevel, experience, damage;


    void Start()
    {
        damage = 40;
        playerLevel = 1;
        health = 50;
        instance = this; //the key to creating a singleton
    }

    void Update()
    {
        levelUp();
    }

    public static void addExperience(int e)
    {
        experience += e;
    }

    void levelUp()
    {
        if (experience >= xpReqs[playerLevel-1])
        {
            playerLevel++;
            health += 50;
            damage += 40;
        }
    }
}