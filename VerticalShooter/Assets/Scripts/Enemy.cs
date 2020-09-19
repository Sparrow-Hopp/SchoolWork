using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    float respawnX;
    float respawnY = 6;
    // Start is called before the first frame update
    void Start()
    {
        respawnX = transform.position.x;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void Respawn()
    {
        gameObject.SetActive(true);
        Vector2 newPos = new Vector2(respawnX, respawnY);
        transform.position = newPos;
        GetComponent<Rigidbody2D>().velocity = Vector2.zero;
    }

    void OnMouseDown()
    {
        Debug.Log("down");
        gameObject.SetActive(false); //set SetActive to false (deactivating enemies)
        GameManager.singleton.UnlistEnemy(gameObject); //remove enemy reference from activeEnemyList (that lives in the singleton GameManager object)
    }
}
