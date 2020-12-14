using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public int [] xpReqs = new int [20];

    // GameManager will appear to be a public static class.
    private static GameManager instance;

    public GameObject player;

    public int health;
    public static int playerLevel, experience, damage;


    void Start()
    {
        DontDestroyOnLoad(transform.gameObject);
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