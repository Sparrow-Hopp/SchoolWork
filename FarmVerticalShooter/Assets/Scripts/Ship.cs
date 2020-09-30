using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Ship : MonoBehaviour
{

    public GameObject explosionPrefab;

    int damage = 0;
    int numPumpkins;
    public int health;
    public Text livesText;
    public string sceneName;
    void Start()
    {
        numPumpkins = GameObject.FindGameObjectsWithTag("Pumpkin").Length;
    }
    void Update()
    {
        livesText.text = health.ToString();
        numPumpkins = GameObject.FindGameObjectsWithTag("Pumpkin").Length;//update the number of pumpkins currently active
        if (numPumpkins == 0)//if all pumpkins are destroyed
        {
            SceneManager.LoadScene(sceneName);
        }        
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Enemy")
        {
            Instantiate(explosionPrefab, transform.position, transform.rotation);

            //GameManager.singleton.UpdateHealth(damage);//PROBLEM HERE WITH UPDATING HEALTH

            //how and when might one have the Ship "blow up?" 

            health--;//cut the health each time ship collides with enemy
            if (health == 0)
            {
                SceneManager.LoadScene(sceneName);//move to game over scene if player is dead
            }
        }
    }
}