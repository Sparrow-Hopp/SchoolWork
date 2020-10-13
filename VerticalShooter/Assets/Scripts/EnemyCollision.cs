using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyCollision : MonoBehaviour
{
    public GameObject explosionPrefab;
    
    //int damage = 0;
    void OnCollisionEnter2D(Collision2D collision)
    {
        Instantiate(explosionPrefab, transform.position, transform.rotation);
        //GameManager.singleton.UpdateHealth(damage); //how can this call be restricted to only be damaged by lasers?
        //Destroy(gameObject); //note that this will actually destroy the object. Watch it in the Hierarchy.
        //how to get the enemies to respawn? Here is a way that is consistent with setActive, but scaling the number of enemies becomes a problem too.
        gameObject.SetActive(false); //set SetActive to false (deactivating enemies)
        GameManager.singleton.UnlistEnemy(gameObject); //remove enemy reference from activeEnemyList (that lives in the singleton GameManager object)
    }
}
