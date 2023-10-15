using Unity.Entities;
using Unity.Transforms;


/// <summary>
/// Example System for using EntityCommandBuffer in UnityDOTS
/// </summary>
[UpdateAfter(typeof(BulletTriggerSystem))]
public class PlayerDeathDetectSystem : SystemBase
{
    private EndSimulationEntityCommandBufferSystem endSimulationEntityCommandBufferSystem;

    protected override void OnCreate()
    {
        endSimulationEntityCommandBufferSystem = World.GetExistingSystem<EndSimulationEntityCommandBufferSystem>();
    }

    protected override void OnUpdate()
    {
        var ecb = endSimulationEntityCommandBufferSystem.CreateCommandBuffer().AsParallelWriter();

        Entities.WithAll<Player>().ForEach(
            (int entityInQueryIndex, Entity entity, in Health health, in Translation translation) =>
            {
                if (health.CurrentHp > 0) return;
                ecb.DestroyEntity(entityInQueryIndex, entity);
            }).ScheduleParallel();

        
        endSimulationEntityCommandBufferSystem.AddJobHandleForProducer(Dependency);
    }
}